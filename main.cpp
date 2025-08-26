#include "crow_all.h"
#include <iostream>
using namespace std;

int main() {
	crow::SimpleApp app;

	CROW_ROUTE(app, "/<string>")([](std::string name){ 
							            auto page = crow::mustache::load("fancypage.html");
							                    crow::mustache::context ctx ({{"person", name}});  
							                            return page.render(ctx);
							                                });
}
