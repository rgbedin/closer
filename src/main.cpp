#include "Closer.hpp"

using ::bb::cascades::Application;

Q_DECL_EXPORT int main(int argc, char **argv) {

	Application app(argc, argv);
	Closer mainApp;
	mainApp.onStart();
	return Application::exec();
}
