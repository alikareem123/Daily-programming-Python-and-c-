function flatArray(arr, n) {
  if (n === 0) return arr;
  const res = [];
  for (let i = 0; i < array.length; i++) {
    if (typeof arr[i] === "number") {
      res.push(arr[i]);
    } else {
      res.push(...flatArray(arr[i], n - 1));
    }
  }
  return res;
}
