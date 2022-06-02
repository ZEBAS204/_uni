-- *
-- * Definir la función combinatoria tal que represente el número de combinaciones de N elementos, tomados de M en M elementos.
-- *

-- Funcion combinatoria de N elementos tomados de M en M elementos
-- combinatoria :: Integer -> Integer -> Integer
combinatoria n m = product [n,m..1]

main = do
  let n = 7
  let m = 7
  let f = combinatoria n m
  putStrLn("La funcion combinatoria de "++ show n)
  putStrLn("de "++ show m ++ " elementos es " ++ show f)