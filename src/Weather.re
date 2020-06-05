open Utils;

[@react.component]
let make = (~data: Api.weatherData) =>
  <div>
    <h2> {s(data.location)} </h2>
    <p> {s(data.description)} </p>
    <p> {s(data.icon)} </p>
    <p> {s(Js.Float.toString(data.temp))} </p>
  </div>;