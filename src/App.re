open Utils;
open Api;

[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

[@react.component]
let make = () => {
  React.useEffect0(() => {
    Js.Promise.(
      fetch(getWeatherByCity("las vegas"))
      |> then_(response => response##json())
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