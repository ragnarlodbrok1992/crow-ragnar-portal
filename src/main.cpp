#include "crow.h"

int main(int argc, char** argv) {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Hello, world!";
    });

    CROW_ROUTE(app, "/json")
    ([]{
        crow::json::wvalue x({{"message", "Hello, world!"}});
        x["message_2"] = "Hello, World.. Again!";
        return x;
    });

    app.port(18080).multithreaded().run();

    return 0;
}
