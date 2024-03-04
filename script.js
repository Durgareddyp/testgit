
const varVariable = "I'm defined with var";

if (true) {
  const varVariable = "Defined inside if with var";
}
console.log(varVariable); // Works, because const is function-scoped or globally-scoped, not block-scoped

// Using let
// console.log(letVariable); // Would throw a ReferenceError if uncommented, because letVariable is not hoisted
let letVariable = "I'm defined with let";

if (true) {
  let letVariable = "Defined inside if with let";
}

console.log(letVariable)
// console.log(letVariableInsideIf); // Would throw a ReferenceError if uncommented, because letVariableInsideIf is block-scoped
