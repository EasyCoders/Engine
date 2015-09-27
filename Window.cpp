#include "stdafx.h"
#include "Window.h"


Window::Window()
{
}

Window::~Window()
{
}

bool Window::init(const char* title, int xpos, int ypos, int width,
	int height, int flags)
{
	// попытка инициализировать SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		// Инициализация окна
		m_pWindow = SDL_CreateWindow(title, xpos, ypos,
			width, height, flags);
		if (m_pWindow != 0) // успех
		{
			std::cout << "window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0) // Инициализация рендера успех
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // Инициализация рендера провал
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // Инициализация окна провал
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // Инициализация SDL провал
	}
	
	std::cout << "init success\n";
	m_bRunning = true; // Все инициализировано успешно, запуск мэйна

	return true;
}

void Window::render()
{
	SDL_RenderClear(m_pRenderer); // очищает текущую цель рендеринга 
	SDL_RenderPresent(m_pRenderer); // рисует на экране
}

void Window::clean()
{
	std::cout << "cleaning Window\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Window::handleEvents()  // обработчик событий(дает возможность управлять окном)
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}
void Window::update()
{
	
}
