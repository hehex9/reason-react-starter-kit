type state = {route: Router.route};

type action =
  | ChangeRoute(Router.route);

let component = React.reducerComponent("App");

let renderTabViews = (r: Router.route) =>
  <div className="tabs-page">
    {
      switch (r) {
      | Featured => <FeaturedView />
      | Subscription => <SubscriptionView />
      | Favorites => <FavoritesView />
      | _ => <FeaturedView />
      }
    }
    <Tabs route=r />
  </div>;

let make = _children => {
  ...component,

  initialState: () => {route: Router.currentRoute()},

  reducer: (action, _state) =>
    switch (action) {
    | ChangeRoute(route) => React.Update({route: route})
    },

  didMount: self => {
    let watchId =
      Router.watchUrl(url =>
        self.send(ChangeRoute(url |> Router.mapUrlToRoute))
      );

    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watchId));
  },

  render: self => {
    let {route} = self.state;

    switch (route) {
    | Featured
    | Subscription
    | Favorites => route |> renderTabViews
    | _ => <NotFoundView />
    };
  },
};