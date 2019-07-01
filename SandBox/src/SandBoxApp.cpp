#include <Spacious.h>

class SandBox : public Spacious::Application {

public:
	SandBox() {

	}
	~SandBox() {

	}
};

Spacious::Application* Spacious::CreateApplication() {
	return new SandBox();
}