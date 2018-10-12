let component = React.statelessComponent("Not Found");

let make = _children => {
  ...component,

  render: _self =>
    <h1
      style={
        ReactDOMRe.Style.make(
          ~height="10rem",
          ~justifyContent="center",
          ~alignItems="center",
          ~display="flex",
          (),
        )
      }>
      {React.string("404")}
    </h1>,
};