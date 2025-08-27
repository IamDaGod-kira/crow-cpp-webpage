#include <iostream>
#include "crow_all.h"
using namespace std;

int main() {
	crow::SimpleApp app;

	CROW_ROUTE(app, "/")([]{
		auto file = crow::mustache::load_text("index.html");
		return file;
		
});
	
	CROW_ROUTE(app, "/page2")([] {
		auto page2 = crow::mustache::load_text("page.html");
		return page2;
		});

	app.port(8080).multithreaded().run();
}
