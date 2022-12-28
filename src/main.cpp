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

    CROW_ROUTE(app, "/hello/<int>")
    ([](int count){
        if (count > 100) return crow::response(400);
        std::ostringstream os;
        os << count << " bottles of beer!";
        return crow::response(os.str());
    });

    CROW_ROUTE(app, "/add_json")
    .methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body);
        if (!x)
            return crow::response(crow::status::BAD_REQUEST); // same as crow::response(400) <-- this is enumed
        int sum = x["a"].i() + x["b"].i();
        std::ostringstream os;
        os << sum;
        return crow::response{os.str()};
    });

    app.port(18080).multithreaded().run();

    return 0;
}
