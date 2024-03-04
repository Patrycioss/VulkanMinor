﻿#pragma once

#include "../window.hpp"

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

class Win32Window : public Window
{
private:
	WNDCLASSEX window{};
	HWND hwnd{};
	LPCSTR windowTitle;
	const LPCSTR WINDOW_CLASS_NAME = "MyWindow";
	bool shouldClose = false;

	LRESULT CALLBACK windowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

public:
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	
	explicit Win32Window(const std::function<void()>& renderFunction, LPCSTR windowTitle = "My Window");
	
	void Setup(int width, int height) override;
	void Run() override;
	void Destroy() override;
};