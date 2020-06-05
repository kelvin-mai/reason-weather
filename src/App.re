open Utils;
open Api;

[@react.component]
let make = () => {
  let (weather, setWeather) = React.useState(() => None);

  React.useEffect0(() => {
    Js.Promise.(
      getWeather(Geo(36.17, -115.14))
      |> then_(data => {
           setWeather(_ => Some(data));
           Js.Promise.resolve();
         })
      |> catch(_err => {
           Js.log(_err);
           setWeather(_ => None);
           Js.Promise.resolve();
         })
      |> ignore
    );
    None;
  });

  Js.log(weather);
  <div>
    {switch (weather) {
     | Some(data) => <Weather data />
     | None => <h1> {s("Loading...")} </h1>
     }}
  </div>;
};