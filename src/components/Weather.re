open Utils;

type temperature =
  | Celsius
  | Fahrenheit;

[@react.component]
let make = (~data: Api.weatherData) => {
  let imgSrc = src => requireImage("../assets/icons/" ++ src ++ ".png");

  let (temp, setTemp) = React.useState(() => Celsius);

  let onClick = _ =>
    switch (temp) {
    | Celsius => setTemp(_ => Fahrenheit)
    | Fahrenheit => setTemp(_ => Celsius)
    };

  <div className="weather-card">
    <img src={data.icon |> imgSrc} alt={data.description} />
    <p> {s(data.location)} </p>
    <p> {s(data.description)} </p>
    <p onClick>
      {(
         switch (temp) {
         | Celsius => kToC(data.temp)
         | Fahrenheit => kToF(data.temp)
         }
       )
       |> Js.Float.toString
       |> s}
    </p>
  </div>;
};