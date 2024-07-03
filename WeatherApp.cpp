#include<iostream>
#include<string>
#include<cpprest/http_client.h>
#include<cpprest/filestream.h>

using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::client;

int main()
{
    cout<<"\t+O+O+O+O+O+O+O+O+O+O+O+O+O+O++O+O+O"<<endl;
    cout<<"\tMY WEATHER APP"<<endl;
    cout<<"\t+O+O+O+O+O+O+O+O+O+O+O+O+O+O++O+O+O"<<endl;
    cout<<"\tEnter city name:";
    string city;
    getline(cin,city);

    http_client client(U("https://api.openweathermap.org/data/2.5"));
    uri_builder builder(U("/weather"));
    builder.append_query(U("q"),utility::conversions::to_string_t(city));
    builder.append_query(U("appid"),U("38edd74232658f52872994a3c0a3b69e"));
    https_request requets(methods::GET);
    request.set_request_uri(builder.to_string());
    client.request(request).then([](https_response response){
        return response.extract_json();
    }
    ).then([](web::json::value body){
        cout<<"\tTemperature : "<<body[U("main")][U("temp")].as_double()<<"K"<<endl;
        cout<<"\tHumidity: "<<body[U("main")][U("humidity")].as_double()<<"%"<<endl;
        cout<<"\tWeather : "<<utility::conversions::to_utf8string(body[U("weather")][0][U("main")].as_string());

    }).wait();
    return 0;
}