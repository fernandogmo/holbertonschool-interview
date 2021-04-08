#!/usr/bin/node
const request = require('request');

const requestAsync = (url) => {
  return new Promise((resolve, reject) => {
    request(url, (err, resp, body) => {
      (err) ? reject(err) : resolve([resp, body]);
    });
  });
};

request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}`,
  async (err, resp, body) => {
    if (err) throw err; // TODO don't throw in async?
    if (resp && resp.statusCode === 200) {
      for (const url of JSON.parse(body).characters) {
        await requestAsync(url)
          .then(([_resp, body]) => console.log(JSON.parse(body).name))
          .catch((err) => console.log(`Oops! : ${err}`));
      }
    }
  });
