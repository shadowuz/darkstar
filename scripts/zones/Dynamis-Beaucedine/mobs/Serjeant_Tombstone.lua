-----------------------------------
-- Area: Dynamis Beaucedine
-- NPC:  Serjeant Tombstone
-- Map Position: http://images1.wikia.nocookie.net/__cb20090312005233/ffxi/images/thumb/b/b6/Bea.jpg/375px-Bea.jpg
-----------------------------------
package.loaded["scripts/zones/Dynamis-Beaucedine/TextIDs"] = nil;
-----------------------------------
require("scripts/globals/status");
require("scripts/globals/dynamis");
require("scripts/zones/Dynamis-Beaucedine/TextIDs");

-----------------------------------
-- onMobSpawn Action
-----------------------------------

function onMobSpawn(mob)
	mob:setMobMod(MOBMOD_SUPERLINK, mob:getShortID());
end;

-----------------------------------
-- onMobEngaged
-----------------------------------

function onMobEngaged(mob,target)
    dynamis.spawnGroup(mob, beaucedineOrcishList, 4);
end;

-----------------------------------
-- onMobDeath
-----------------------------------

function onMobDeath(mob,killer)
	
	local mobID = mob:getID();
	-- Time Bonus: 083 087
	if (mobID == 17326912 and mob:isInBattlefieldList() == false) then
		killer:addTimeToDynamis(15);
		mob:addInBattlefieldList();
	elseif (mobID == 17326916 and mob:isInBattlefieldList() == false) then
		killer:addTimeToDynamis(15);
		mob:addInBattlefieldList();
	-- HP Bonus: 078 084 086 091 095 105
	elseif (mobID == 17326907 or mobID == 17326913 or mobID == 17326915 or mobID == 17326920 or mobID == 17326924 or mobID == 17326934) then 
		killer:restoreHP(2000);
		killer:messageBasic(024,(killer:getMaxHP()-killer:getHP()));
	-- MP Bonus: 080 082 088 094 098 
	elseif (mobID == 17326909 or mobID == 17326911 or mobID == 17326917 or mobID == 17326923 or mobID == 17326927) then 
		killer:restoreMP(2000);
		killer:messageBasic(025,(killer:getMaxMP()-killer:getMP()));
	end
	
end;
