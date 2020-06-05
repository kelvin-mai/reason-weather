open Decode;

type weatherData = {
  temp: float,
  location: string,
  description: string,
  icon: string,
};

let formatWeatherData = (w: response) => {
  temp: w.main.temp,
  location: w.name,
  description: w.weather[0].description,
  icon: w.weather[0].icon,
};

let api =
  "https://api.openweathermap.org/data/2.5/weather?appid=" ++ Env.api_key;
let apiByCity = city => api ++ "&q=" ++ city;
let apiByGeo = (lat, lon) =>
  api
  ++ "&lat="
  ++ Js.Float.toString(lat)
  ++ "&lon="
  ++ Js.Float.toString(lon);

type apiBy =
  | City(string)
  | Geo(float, float);

let getEndpoint = q =>
  switch (q) {
  | City(city) => apiByCity(city)
  | Geo(lat, lon) => apiByGeo(lat, lon)
  };

let fetchWeather = endpoint =>
  Js.Promise.(
    Fetch.fetch(endpoint)
    |> then_(Fetch.Response.json)
    |> then_(json => {
         Js.log(json);
         json |> decodeResponse |> formatWeatherData |> resolve;
       })
  );

let getWeather = q => q |> getEndpoint |> fetchWeather;