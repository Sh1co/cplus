var x : integer is 3;

routine convertToMiles(x : integer) : real is
  var convertFactor : real is 0.621371;
  return x * convertFactor;
end

var miles : real is convertToMiles(x);
println miles;

# for the correct code

/*

var x : integer is 3;

routine convertToMiles(x : integer) : real is
  var convertFactor : real is 0.621371;
  return x * convertFactor;
end

routine main() is
  var miles : real is convertToMiles(x);
  println miles;
  return;
end

*/
