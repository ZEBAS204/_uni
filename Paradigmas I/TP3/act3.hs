-- *
-- * Definir la función divisor N de M, para determinar si N es divisor de M
-- *

-- isDivisible :: Int -> Int -> Bool
isDivisible n m = n `mod` m == 0

main = do
  let n = 7
  let m = 5
  putStr("Es " ++ show n ++ " divisor de " ++ show m ++"? ")
  putStrLn(id (if (isDivisible n m) then "Si" else "No"))