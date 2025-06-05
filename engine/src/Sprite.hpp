#include "pch/engine_pch.h"
#pragma once

namespace engine {
	class Sprite {
	public:
		Sprite(std::vector<std::vector<char>> body) {
			this->body = body;
		}
		std::vector<std::vector<char>> getBody(){
			return this->body;
		}
	private:
		std::vector<std::vector<char>> body;
	};


}