type main = {temp: float};

type weather = {
  description: string,
  icon: string,
};

type response = {
  main,
  name: string,
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
    name: json |> field("name", string),
    main: json |> field("main", decodeMain),
    weather: json |> field("weather", array(decodeWeather)),
  };