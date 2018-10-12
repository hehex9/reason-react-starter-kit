const path = require('path')
const HtmlWebpackPlugin = require('html-webpack-plugin')
const paths = require('./paths')

const isProd = process.env.NODE_ENV === 'production'

module.exports = {
  mode: isProd ? 'production' : 'development',

  entry: [paths.appIndexJs],

  devtool: 'cheap-module-source-map',

  output: {
    path: isProd ? paths.appBuild : undefined,
    pathinfo: true,
    publicPath: '/',
    filename: 'js/app.js',
    chunkFilename: 'js/[name].chunk.js',
  },

  optimization: {
    splitChunks: {
      chunks: 'all',
      name: true,
    },
    runtimeChunk: true,
  },

  module: {
    rules: [
      {
        test: /\.styl$/,
        use: ['style-loader', 'css-loader', 'stylus-loader'],
      },
    ],
  },

  resolve: {
    modules: [path.resolve(__dirname, '../src'), 'node_modules'],
  },

  plugins: [
    new HtmlWebpackPlugin({
      inject: true,
      template: paths.appHtml,
    }),
  ],

  devServer: {
    compress: true,
    contentBase: paths.appPublic,
    watchContentBase: true,
    port: process.env.PORT || 9000,
  },
}
