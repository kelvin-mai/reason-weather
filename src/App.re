open Utils;
open Api;

[@react.component]
let make = () => {
  let (weather, setWeather) = React.useState(() => None);
  let (value, setValue) = React.useState(() => "");

  let onSubmit = e => {
    e |> ReactEvent.Form.preventDefault;
    Js.Promise.(
      getWeather(City(value))
      |> then_(data => setWeather(_ => Some(data)) |> resolve)
      |> catch(_err => {
           Js.log(_err);
           setWeather(_ => None) |> resolve;
         })
      |> ignore
    );
  };

  React.useEffect0(() => {
    Js.Promise.(
      getWeather(Geo(36.17, -115.14))
      |> then_(data => setWeather(_ => Some(data)) |> resolve)
      |> catch(_err => {
           Js.log(_err);
           setWeather(_ => None) |> resolve;
         })
      |> ignore
    );
    None;
  });

  <div className="container">
    <form onSubmit>
      <input
        type_="text"
        placeholder="Enter city"
        value
        onChange={e => e->ReactEvent.Form.target##value |> setValue}
      />
      <button type_="submit"> {s("Submit")} </button>
    </form>
    {switch (weather) {
     | Some(data) => <Weather data />
     | None => <h1> {s("Loading...")} </h1>
     }}
  </div>;
};