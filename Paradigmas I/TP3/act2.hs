-- *
-- * Definir la función potencia N de M
-- *

-- power_m :: int -> int -> double
power_m n m = n^m

main = do
  let n = 7
  let m = 7

  putStrLn("La potencia de " ++ show n ++ "^" ++ show m)
  putStr("es igual a: ")
  print(power_m n m)