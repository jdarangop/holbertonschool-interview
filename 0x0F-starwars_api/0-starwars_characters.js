#!/usr/bin/node

const request = require('request');

request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], async function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    const characters = JSON.parse(body).characters;
    for (const i in characters) {
      const prom = new Promise((resolve, reject) => {
        request(characters[i], function (error, response, body) {
          if (error) {
            reject(error);
          } else {
            resolve(body);
          }
        });
      });
      await prom.then(body => console.log(JSON.parse(body).name)).catch(error => console.log(error));
    }
  }
});
