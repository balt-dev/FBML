
local printed = false

function p.update()
	if not printed then
		printed = true
		ga_console_print(multiplayerLib.testFunction())
	end
end

function p.update_passive()
    
end

UPDATE_COUNTER = 0
LEVEL_MAX = 512
UPDATE_FREQUENCY = 2

p.MULTIPLAYER_DATA = {}

function p.update_discrete_pre()
end

function p.update_discrete_post()
end
