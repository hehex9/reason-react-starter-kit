type state = {list: list(string)};

type action =
  | Refresh
  | FetchData;

let renderItemCard = (data: string) => <ItemCard key=data data />;

let component = React.reducerComponent("FeaturedView");

let make = _children => {
  ...component,

  initialState: () => {list: ["1"]},

  reducer: (action, _state) =>
    switch (action) {
    | FetchData => React.Update({list: ["1", "2", "3"]})
    | Refresh => React.Update({list: []})
    },

  didMount: self => self.send(FetchData),

  render: self => {
    let items = List.map(renderItemCard, self.state.list);

    <div className="featured-container">
      {React.array(Array.of_list(items))}
    </div>;
  },
};