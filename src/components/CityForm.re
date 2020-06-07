open Utils;

[@react.component]
let make = (~onCity) => {
  let (value, setValue) = React.useState(() => "");

  let onSubmit = e => {
    ReactEvent.Form.preventDefault(e);
    Api.City(value) |> onCity;
  };

  <form onSubmit className="city-form">
    <input
      type_="text"
      placeholder="Enter city"
      value
      onChange={e => e->ReactEvent.Form.target##value |> setValue}
    />
    <button type_="submit"> {s("Submit")} </button>
  </form>;
};