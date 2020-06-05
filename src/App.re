open Utils;
open Api;

[@react.component]
let make = () => {
  React.useEffect0(() => {
    Js.Promise.(
      Fetch.fetch(getWeatherByCity("las vegas"))
      |> then_(Fetch.Response.json)
      |> then_(json => {
           Js.log(json |> Api.decodeResponse);
           Js.log(json);
           Js.Promise.resolve();
         })
      |> catch(_err => {
           Js.log(_err);
           Js.Promise.resolve();
         })
      |> ignore
    );
    None;
  });
  <div> {s("Hello world")} </div>;
};