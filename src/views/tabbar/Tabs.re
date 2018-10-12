Import.style("./style.styl");

type state = {tab: Router.route};

type action =
  | ChangeTab(Router.route);

let tabItemClass = (active: bool): string =>
  active ? "tabbar-item tabbar-item--active" : "tabbar-item";

let component = React.reducerComponent("Tabs");

let make = (~route, _children) => {
  ...component,

  initialState: () => {tab: route},

  reducer: (action, state) =>
    switch (action) {
    | ChangeTab(nextTab) =>
      if (nextTab == state.tab) {
        React.NoUpdate;
      } else {
        Router.push(nextTab);
        React.Update({tab: nextTab});
      }
    },

  render: self => {
    let {tab} = self.state;

    <div className="tabbar hairline hairline-top">
      <div
        className={tabItemClass(tab == Featured)}
        onClick={_e => self.send(ChangeTab(Featured))}>
        <i className="icon ion-ios-ice-cream" />
      </div>
      <div
        className={tabItemClass(tab == Subscription)}
        onClick={_e => self.send(ChangeTab(Subscription))}>
        <i className="icon ion-ios-bookmark" />
      </div>
      <div
        className={tabItemClass(tab == Favorites)}
        onClick={_e => self.send(ChangeTab(Favorites))}>
        <i className="icon ion-ios-heart" />
      </div>
    </div>;
  },
};