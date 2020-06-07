let s = React.string;

[@bs.val] external requireCSS: string => unit = "require";

[@bs.val] external requireImage: string => string = "require";

let kToC = k => k -. 273.15;

let kToF = k => kToC(k) *. 9. /. 5. +. 32.;