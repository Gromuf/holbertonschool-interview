#!/usr/bin/node

const request = require("request");
const movieId = process.argv[2];
const url = `https://swapi.dev/api/films/${movieId}/`;
request(url, (err, res, body) => {
  if (err) {
    return console.log(err);
  }
  const film = JSON.parse(body);
  const characters = film.characters;
  printCharacters(characters, 0);
});
function printCharacters(list, index) {
  if (index === list.length) {
    return;
  }
  request(list[index], (err, res, body) => {
    if (!err) {
      const character = JSON.parse(body);
      console.log(character.name);
      printCharacters(list, index + 1);
    } else {
      console.log(err);
    }
  });
}
