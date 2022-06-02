-- *
-- * Definir la función paridad N para determinar si en numero N es par o impar
-- *

-- paridad :: Integer -> Bool
paridad n = mod n 2 == 0

main = do
  let n = 7
  putStrLn("Es "++ show n ++ " par? " ++ id (if (paridad n) then "SI" else "NO"))