let component = React.statelessComponent("Favorites");

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
      {React.string("favorites")}
    </h1>,
};