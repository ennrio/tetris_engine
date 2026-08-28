//#include "src/graphics/Graphics.hpp"
#include "Graphics.hpp"


bool engine::Graphics::Init(EWindowMode mode, int width, int height, bool frame) {

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window;


    if (!glfwInit()) {
        return false;
    }

    // Настройка окна
    if (!width) {
        width = 100;
    }
    if (!height) {
        height = 100;
    }
    window = glfwCreateWindow(width, height, "GLFW Window", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return false;
    }

    if (!frame) {
        glfwSetWindowAttrib(window, GLFW_DECORATED, GLFW_FALSE);
    }


    glfwMakeContextCurrent(window);

    switch (mode)
    {
    case areaWindow:
    {
        //режим с учётом панели windows
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        int m_x, m_y, m_width, m_height;
        glfwGetMonitorWorkarea(monitor, &m_x, &m_y, &m_width, &m_height);
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);

        if (frame) {// TODO
            int left; int top;
            int right; int bottom;
            glfwGetWindowFrameSize(window, &left, &top, &right, &bottom);
            m_height -= top;
            m_y += top;
        }

        glfwSetWindowSize(window, m_width, m_height);
        glfwSetWindowPos(window, m_x, m_y);
        if (!(width + height)) {
            //TODO предупреждение о том, что в таком режиме нельзя задавать размеры окна, а ещё при дальнейшей попытке задать размеры окна режим переключится автоматически
        }
        break;
    }
    case fullScreen:
    {
        //Полноэкранный режим
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        glfwSetWindowMonitor(window, monitor, 0, 0,
            mode->width, mode->height,
            mode->refreshRate);
        if (!(width + height)) {
            //TODO предупреждение о том, что в таком режиме нельзя задавать размеры окна, а ещё при дальнейшей попытке задать размеры окна режим переключится автоматически
        }
        break;
    }
    }
    

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Вершинный шейдер (обрабатывает вершины)
    const char* vertexShaderSource = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    void main() {
        gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    }
    )";

    // Фрагментный шейдер (определяет цвет пикселей)
    const char* fragmentShaderSource = R"(
    #version 330 core
    out vec4 FragColor;
    void main() {
        FragColor = vec4(1.0, 0.5, 0.2, 1.0); // Оранжевый цвет
    }
    )";


    // Компиляция шейдеров
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Создание шейдерной программы
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Удаление шейдеров (они уже в программе)
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Вершины треугольника (в NDC-координатах от -1 до 1)
    float vertices[] = {
        -0.5f,  0.5f, 0.0f,  // 0: левый верхний
        -0.5f, -0.5f, 0.0f,  // 1: левый нижний
         0.5f, -0.5f, 0.0f,  // 2: правый нижний
         0.5f,  0.5f, 0.0f   // 3: правый верхний
    };

    unsigned int indices[] = {
    0, 1, 2,  // первый треугольник
    0, 2, 3   // второй треугольник
    };

    // Создание VAO и VBO
    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

     unsigned int EBO;
    glGenBuffers(1, &EBO);

    // Привязка VAO и VBO
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Указываем, как интерпретировать вершины
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Основной цикл рендеринга
    while (!glfwWindowShouldClose(window)) {
        // Очистка буфера цвета
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Используем шейдерную программу и рисуем треугольник
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // Обмен буферов и обработка событий
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Очистка ресурсов
    glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);


    return true;
}

void engine::Graphics::Terminate() {
    glfwTerminate();
}