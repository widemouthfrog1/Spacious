#pragma once

#ifdef SP_PLATFORM_WINDOWS

extern Spacious::Application* Spacious::CreateApplication();

int main(int argc, char** argv) {
	auto app = Spacious::CreateApplication();
	app->Run();
	delete app;
}

#endif