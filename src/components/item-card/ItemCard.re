Import.style("./style.styl");

let component = React.statelessComponent("ItemCard");

let make = (~data, _children) => {
  ...component,

  render: _self =>
    <div className="item-card"> <p> {React.string(data)} </p> </div>,
};