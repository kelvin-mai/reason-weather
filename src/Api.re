type main = {temp: float};

type weather = {
  description: string,
  icon: string,
};

type response = {
  main,
  weather: array(weather),
};

let decodeMain = json => Json.Decode.{temp: json |> field("temp", float)};
let decodeWeather = json =>
  Json.Decode.{
    description: json |> field("description", string),
    icon: json |> field("icon", string),
  };
let decodeResponse = json =>
  Json.Decode.{
    main: json |> field("main", decodeMain),
    weather: json |> field("weather", array(decodeWeather)),
  };

let api =
  "https://api.openweathermap.org/data/2.5/weather?appid=" ++ Env.api_key;

let getWeatherByCity = city => api ++ "&q=" ++ city;

let getWeatherByGeo = (lat, lon) =>
  api
  ++ "&lat="
  ++ Js.Float.toString(lat)
  ++ "&lon="
  ++ Js.Float.toString(lon);