'use strict';

const { private: p } = require('bindings')('private');

function PrivateSymbol(desc) {
  if (new.target !== undefined) {
    throw new TypeError('PrivateSymbol is not a constructor');
  }
  return p(desc);
}

module.exports = PrivateSymbol;
