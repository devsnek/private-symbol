# @snek/private

Completely unenumerable symbols that you can use
to store private data on any object. Only those
with access to the symbol can access the data.

```js
const PS = require('@snek/private');

const mySecret = PS('mySecret');
class MyClass {
  constructor(x) {
    this[mySecret] = x;
  }

  add(y) {
    return this[mySecret] + y;
  }
}

const obj = {};
obj[mySecret] = 5;
```
