let component = React.statelessComponent("Subscription");

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
      {React.string("subscription")}
    </h1>,
};