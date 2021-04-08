# 0x0F. Star Wars API
NodeJS script that prints all characters of a Star Wars movie.

## Usage
*Make sure you have `node` installed as well as the `request` module.*

As an example, to print the characters in *Return of the Jedi*, the 3rd Star Wars movie (based on release date):
```sh
$ ./0-starwars_characters.js 3
Luke Skywalker
C-3PO
R2-D2
Darth Vader
Leia Organa
Obi-Wan Kenobi
Chewbacca
Han Solo
Jabba Desilijic Tiure
Wedge Antilles
Yoda
Palpatine
Boba Fett
Lando Calrissian
Ackbar
Mon Mothma
Arvel Crynyd
Wicket Systri Warrick
Nien Nunb
Bib Fortuna
$
```

## Setup
Project specifications require to project to run on a legacy system using `node v10.14.x` and the now-deprecated `request` module.

The Holberton School style guidelines require `semistandard` compliance and suggest the [AirBnB Style Guide](https://github.com/airbnb/javacript) as a reference.

### Node
I'll be using two versions of `node` for development and testing.

For initial development, I'll be using a current `LTS` version:
```sh
$ nvm install --lts
...
$ nvm current
v14.16.1
$
```
Use `nvm` to install `node v10.14.x`.
```sh
$ nvm install v10.14
...
$ nvm current
v10.14.2
$
```
We can switch back to the latest LTS by running `nvm use --lts`.

Run `npm init --yes` to create a `package.json` with default values. *Note: we might not push the `package.json` if it somehow interferes with the Holberton School checker setup.*

### Semistandard
The Holberton School checker should already have `semistandard` installed globally and I don't want to trigger another +30MB download and installation. Therefore, I'll tentatively install `semistandard` globally and specifically not add it to my `devDependencies`:
```sh
$ npm install -g semistandard
$HOME/.nvm/versions/node/v14.16.1/bin/semistandard -> $HOME/.nvm/versions/node/v14.16.1/lib/node_modules/semistandard/bin/cmd.js
+ semistandard@16.0.0
added 221 packages from 105 contributors in 8.393s
$
```
### Request
For the same reasons as when I installed `semistandard`, I'll install `request` globally instead of adding it to `dependencies` in my `package.json`:
```sh
$ npm install -g request
npm WARN deprecated request@2.88.2: request has been deprecated, see https://github.com/request/request/issues/3142
npm WARN deprecated har-validator@5.1.5: this library is no longer supported
+ request@2.88.2
added 47 packages from 58 contributors in 11.92s
$
```
*Note all the warnings--that's why I'll implement a modern version of this as `1-starwars_characters.js` for any hippokampiers wanting to learn from this repo.*

We're going to link to global `request` module into our local `node_modules` so we can use:
```sh
$ npm link request
/home/fernando/repos/holbertonschool-interview/0x0F-starwars_api/node_modules/request -> /home/fernando/.nvm/versions/node/v14.16.1/lib/node_modules/request
```

## Implementation
If we ignore the stric order requirements, we'd be able to print all the characters with the following:
```js
const request = require('request');

request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}`, (err, resp, body) => {
  if (err) throw err;
  if (resp && resp.statusCode === 200) {
    JSON.parse(body).characters.forEach(url => {
      request(url, (_, resp, body) => {
        const character = JSON.parse(body);
        console.log(character.name);
      });
    });
  }
});
```
However, we cannot await a call to `request` because it doesn't return a `Promise`. The calls to `request` will return as they are completed--which is good for performance but will make the print order non-deterministic.

We can control the printing order by *promisifying* the `request` api into an `await`-able `requestAsync`.
