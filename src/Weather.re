open Utils;

[@react.component]
let make = (~data: Api.weatherData) => {
  let imgSrc = src => requireImage("./assets/icons/" ++ src ++ ".png");

  <div className="weather-card">
    <img src={data.icon |> imgSrc} alt={data.description} />
    <p> {s(data.location)} </p>
    <p> {s(data.description)} </p>
    <p> {s(Js.Float.toString(data.temp))} </p>
  </div>;
};