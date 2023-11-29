#pragma once
#include <memory>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "../model/World.h"
#include "../view/Screen.h"



namespace rm
{
namespace controller
{
	using std::shared_ptr;


	class Game
	{
	private:
		shared_ptr<sf::RenderWindow> window_;
		shared_ptr<model::World> world_;
		shared_ptr<view::Screen> screen_;

		std::string user_input_;

		void readResource();
		void writeResource();

	public:
		Game();
		~Game();

		void run();

	};








}
}



