#include "crow_all.h"
#include <iostream>
using namespace std;

int main() {
	crow::SimpleApp app;

	CROW_ROUTE(app, "/")([](){
			        auto page = crow::mustache::load_text("index.html");
				        return page;
					    });
}
