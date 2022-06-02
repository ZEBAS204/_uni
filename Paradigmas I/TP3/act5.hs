-- *
-- * Definir la función factorial de N
-- *

-- factorial :: int -> int -> double
factorial n = product [1..n]

main = do
  let n = 7
  let f = factorial n
  putStrLn("El factorial de "++ show n ++ " es " ++ show f)