let geo: option('a) = [%bs.raw {|navigator.geolocation|}];

[@bs.val]
external getCurrentPosition:
  (~onSuccess: 'a => unit, ~onError: 'b => unit) => unit =
  "navigator.geolocation.getCurrentPosition";

let onSuccess = p => Js.log2(p##coords##latitude, p##coords##longitude);
let onError = e => {
  let msg =
    switch (e##code) {
    | 1 => "Permission denied"
    | 2 => "Position unavailable"
    | 3 => "Timeout"
    | _ => "Unknown error"
    };
  Js.log(msg);
};

switch (geo) {
| Some(_) => getCurrentPosition(~onSuccess, ~onError)
| None => Js.log("Not available")
};