-- *
-- * Definir una función que tome como parámetro un Lista de números y realice su promedio
-- *

promedioAll :: [Float] -> Float
promedioAll [] = 0
promedioAll (x:xs) = sum xs `div` length xs


main = do
  let n = [1,2,3,4,5]

  putStr("El promedio de los numeros "++ show n ++" es: " ++ show(promedioAll n))