#!/usr/bin/node

const request = require('request');
const ep = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/'.concat(ep);
const result = {};
request(url, function (error, response, body) {
  if (error) throw error;
  const people = JSON.parse(body).characters;

  people.forEach(character => {
    request(character, function (error, response, body) {
      if (error) throw error;
      result[character] = JSON.parse(body).name;

      if (Object.keys(result).length === people.length) {
        people.forEach(character => {
          console.log(result[character]);
        });
      }
    });
  });
});
