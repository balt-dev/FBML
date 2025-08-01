---@meta

---@alias Vector {x: number, y: number, z: number}
---@alias BlockPos {x: integer, y: integer, z: integer}
---@alias LocalBlockPos {x: integer, y: integer, z: integer}

---@param block_type string
function clear_all(block_type)
    error("function stub", 2)
end

---@param var string
---@param value boolean
function chunk_set_b(var, value)
    error("function stub", 2)
end

---@param var string
---@param value integer
function chunk_set_i(var, value)
    error("function stub", 2)
end

---@param var string
---@param value number
function chunk_set_f(var, value)
    error("function stub", 2)
end

---@param var string
---@param value Vector
function chunk_set_v(var, value)
    error("function stub", 2)
end

---@param var string
---@param value string
function chunk_set_s(var, value)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
---@param var string
---@param value boolean
function block_set_b(x, y, z, var, value)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
---@param var string
---@param value integer
function block_set_i(x, y, z, var, value)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
---@param var string
---@param value number
function block_set_f(x, y, z, var, value)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
---@param var string
---@param value Vector
function block_set_v(x, y, z, var, value)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
---@param var string
---@param value string
function block_set_s(x, y, z, var, value)
    error("function stub", 2)
end

---@param block_type string
function set_default_block(block_type)
    error("function stub", 2)
end

---@param block_type string
function clear_blocks(block_type)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
---@param block_type string
function set_pos(x, y, z, block_type)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
---@return string
function get_pos(x, y, z)
    error("function stub", 2)
end

---@param block_type string
---@param min_x integer
---@param min_y integer
---@param min_z integer
---@param max_x integer
---@param max_y integer
---@param max_z integer
function create_rect(block_type, min_x, min_y, min_z, max_x, max_y, max_z)
    error("function stub", 2)
end

---@param min_x integer
---@param min_y integer
---@param min_z integer
---@param max_x integer
---@param max_y integer
---@param max_z integer
---@param prob number
---@param block_type string
function create_sprinkles(min_x, min_y, min_z, max_x, max_y, max_z, prob, block_type)
    error("function stub", 2)
end

function maze_start()
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
function maze_add_vertex(x, y, z)
    error("function stub", 2)
end

---@param x1 integer
---@param y1 integer
---@param z1 integer
---@param x2 integer
---@param y2 integer
---@param z2 integer
function maze_add_edge(x1, y1, z1, x2, y2, z2)
    error("function stub", 2)
end

function maze_end()
    error("function stub", 2)
end

---@param x1 integer
---@param y1 integer
---@param z1 integer
---@param x2 integer
---@param y2 integer
---@param z2 integer
---@return boolean
function maze_edge_open(x1, y1, z1, x2, y2, z2)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
---@return integer
function maze_num_edges_from_vertex(x, y, z)
    error("function stub", 2)
end

---@param source_vertices table
---@return table
function maze_deepest_vertex(source_vertices)
    error("function stub", 2)
end

function caves_start()
    error("function stub", 2)
end

function caves_set_5x5x5()
    error("function stub", 2)
end

---@param min_nodes number
---@param max_nodes number
function caves_set_num_nodes(min_nodes, max_nodes)
    error("function stub", 2)
end

---@param frac_large_node number
---@param small_node_min_rad number
---@param small_node_max_rad number
---@param large_node_min_rad number
---@param large_node_max_rad number
function caves_set_nodes(frac_large_node, small_node_min_rad, small_node_max_rad, large_node_min_rad, large_node_max_rad)
    error("function stub", 2)
end

---@param max_edge_dist number
---@param frac_large_edge number
---@param small_edge_min_rad number
---@param small_edge_max_rad number
---@param large_edge_min_rad number
---@param large_edge_max_rad number
function caves_set_edges(max_edge_dist, frac_large_edge, small_edge_min_rad, small_edge_max_rad, large_edge_min_rad, large_edge_max_rad)
    error("function stub", 2)
end

function caves_end()
    error("function stub", 2)
end

---@param seed integer
function srand(seed)
    error("function stub", 2)
end

---@return number
function randf()
    error("function stub", 2)
end

---@param min_i integer
---@param max_i integer
---@return integer
function randi(min_i, max_i)
    error("function stub", 2)
end

---@return integer
function get_level()
    error("function stub", 2)
end

---@return integer
function get_input_path_length()
    error("function stub", 2)
end

---@return table
function get_input_path()
    error("function stub", 2)
end

---@return table
function get_input_path_bts()
    error("function stub", 2)
end

---@param level integer
---@return string
function get_input_path_bt(level)
    error("function stub", 2)
end

---@param dx integer
---@param dy integer
---@param dz integer
---@return string
function get_input_adj_bt(dx, dy, dz)
    error("function stub", 2)
end

---@param dx integer
---@param dy integer
---@param dz integer
---@return string
function get_input_parent_adj_bt(dx, dy, dz)
    error("function stub", 2)
end

---@param level integer
---@param var string
---@param type string
---@return boolean
function get_input_path_block_var_exists(level, var, type)
    error("function stub", 2)
end

---@param level integer
---@param var string
---@return boolean
function get_input_path_block_b(level, var)
    error("function stub", 2)
end

---@param level integer
---@param var string
---@return integer
function get_input_path_block_i(level, var)
    error("function stub", 2)
end

---@param level integer
---@param var string
---@return number
function get_input_path_block_f(level, var)
    error("function stub", 2)
end

---@param level integer
---@param var string
---@return Vector
function get_input_path_block_v(level, var)
    error("function stub", 2)
end

---@param level integer
---@param var string
---@return string
function get_input_path_block_s(level, var)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
---@return boolean
function caves_close_to_node(x, y, z)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
---@return table
function caves_close_to_node2(x, y, z)
    error("function stub", 2)
end

function set_blue_type_up()
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
function set_blue_type_down(x, y, z)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
function set_blue_type_terminal(x, y, z)
    error("function stub", 2)
end

---@param min_x integer
---@param min_y integer
---@param min_z integer
---@param max_x integer
---@param max_y integer
---@param max_z integer
---@param type string
function add_env_rect(min_x, min_y, min_z, max_x, max_y, max_z, type)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
---@param type string
function add_bent(x, y, z, type)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
---@param type string
---@param param integer
function add_bent_i(x, y, z, type, param)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
---@param type string
---@param param string
function add_bent_s(x, y, z, type, param)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
---@param new_param_value integer
function bent_set_param_i(x, y, z, new_param_value)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
---@param new_param_value string
function bent_set_param_s(x, y, z, new_param_value)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
---@return boolean
function caves_close_to_edge(x, y, z)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
---@param type string
function add_ment(x, y, z, type)
    error("function stub", 2)
end

---@param x integer
---@param y integer
---@param z integer
---@param type string
function ment_start(x, y, z, type)
    error("function stub", 2)
end

---@param key string
---@param value boolean
function ment_set_b(key, value)
    error("function stub", 2)
end

---@param key string
---@param value integer
function ment_set_i(key, value)
    error("function stub", 2)
end

---@param key string
---@param value number
function ment_set_f(key, value)
    error("function stub", 2)
end

---@param key string
---@param x number
---@param y number
---@param z number
function ment_set_v(key, x, y, z)
    error("function stub", 2)
end

---@param key string
---@param value string
function ment_set_s(key, value)
    error("function stub", 2)
end

function ment_end()
    error("function stub", 2)
end

---@param block_type string
---@return boolean
function bt_get_is_solid_physically(block_type)
    error("function stub", 2)
end

---@param bt string
function create_xar_chunk(bt)
    error("function stub", 2)
end

---@param str string
function print(str)
    error("function stub", 2)
end

function exit()
    error("function stub", 2)
end

function dump_lua_env()
    error("function stub", 2)
end

---@return integer
function seed_normal()
    error("function stub", 2)
end

---@param dx integer
---@param dy integer
---@param dz integer
---@return integer
function seed_nearby(dx, dy, dz)
    error("function stub", 2)
end

---@return integer
function seed_xy()
    error("function stub", 2)
end

---@return integer
function seed_xz()
    error("function stub", 2)
end

---@return integer
function seed_yz()
    error("function stub", 2)
end

---@param chop integer
---@return integer
function seed_normal_chop(chop)
    error("function stub", 2)
end

---@param dx integer
---@param dy integer
---@param dz integer
---@param chop integer
---@return integer
function seed_nearby_chop(dx, dy, dz, chop)
    error("function stub", 2)
end

---@param chop integer
---@return integer
function seed_xy_chop(chop)
    error("function stub", 2)
end

---@param chop integer
---@return integer
function seed_xz_chop(chop)
    error("function stub", 2)
end

---@param chop integer
---@return integer
function seed_yz_chop(chop)
    error("function stub", 2)
end

---@param type string
---@return integer
function seed_from_last_of_type(type)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param default_value boolean
---@param revert_length number
function ia_ment_new_var_b(tid, var, default_value, revert_length)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param default_value integer
---@param revert_length number
function ia_ment_new_var_i(tid, var, default_value, revert_length)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param default_value number
---@param revert_length number
function ia_ment_new_var_f(tid, var, default_value, revert_length)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param default_value Vector
---@param revert_length number
function ia_ment_new_var_v(tid, var, default_value, revert_length)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param default_value string
---@param revert_length number
function ia_ment_new_var_s(tid, var, default_value, revert_length)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param default_value boolean
function ia_ment_new_var_b_perm(tid, var, default_value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param default_value integer
function ia_ment_new_var_i_perm(tid, var, default_value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param default_value number
function ia_ment_new_var_f_perm(tid, var, default_value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param default_value Vector
function ia_ment_new_var_v_perm(tid, var, default_value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param default_value string
function ia_ment_new_var_s_perm(tid, var, default_value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value boolean
function ia_ment_new_static_var_b(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value integer
function ia_ment_new_static_var_i(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value number
function ia_ment_new_static_var_f(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value Vector
function ia_ment_new_static_var_v(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value string
function ia_ment_new_static_var_s(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value boolean
function ia_ment_set_builtin_var_b(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value integer
function ia_ment_set_builtin_var_i(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value number
function ia_ment_set_builtin_var_f(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value Vector
function ia_ment_set_builtin_var_v(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value string
function ia_ment_set_builtin_var_s(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value boolean
function ia_ment_set_var_saving(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value boolean
function ia_block_new_static_var_b(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value integer
function ia_block_new_static_var_i(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value number
function ia_block_new_static_var_f(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value Vector
function ia_block_new_static_var_v(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value string
function ia_block_new_static_var_s(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value integer
function ia_block_set_builtin_var_i(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value string
function ia_block_set_builtin_var_s(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value boolean
function ia_block_new_var_b(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value integer
function ia_block_new_var_i(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value number
function ia_block_new_var_f(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value Vector
function ia_block_new_var_v(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param value string
function ia_block_new_var_s(tid, var, value)
    error("function stub", 2)
end

---@param tid integer
---@param var string
---@param rl integer
function ia_block_make_var_eph(tid, var, rl)
    error("function stub", 2)
end

---@param tid integer
---@param var string
function ia_block_make_var_not_eph(tid, var)
    error("function stub", 2)
end

---@param command string
---@return string
function ga_command(command)
    error("function stub", 2)
end

---@param play_sound boolean
function ga_save(play_sound)
    error("function stub", 2)
end

function ga_load()
    error("function stub", 2)
end

function ga_exit()
    error("function stub", 2)
end

function ga_exit_with_error()
    error("function stub", 2)
end

---@param line string
function ga_print(line)
    error("function stub", 2)
end

function ga_flush()
    error("function stub", 2)
end

---@param line string
function ga_console_print(line)
    error("function stub", 2)
end

function ga_dump_lua_env()
    error("function stub", 2)
end

---@param frame string
function ga_debug_push(frame)
    error("function stub", 2)
end

---@param frame string
function ga_debug_pop(frame)
    error("function stub", 2)
end

---@param line string
function ga_debug_line(line)
    error("function stub", 2)
end

---@param var string
---@param value boolean
function ga_return_b(var, value)
    error("function stub", 2)
end

---@return number
function ga_get_game_time()
    error("function stub", 2)
end

---@param level integer
---@return number
function ga_get_level_time(level)
    error("function stub", 2)
end

---@return boolean
function ga_get_game_paused()
    error("function stub", 2)
end

---@return integer
function ga_get_high_precision_timer()
    error("function stub", 2)
end

---@param seed integer
function ga_srand(seed)
    error("function stub", 2)
end

---@return integer
function ga_rand()
    error("function stub", 2)
end

---@return number
function ga_randf()
    error("function stub", 2)
end

---@param min_f number
---@param max_f number
---@return number
function ga_randf_range(min_f, max_f)
    error("function stub", 2)
end

---@param min_i integer
---@param max_i integer
---@return integer
function ga_randi(min_i, max_i)
    error("function stub", 2)
end

---@param chunk_id integer
---@return integer
function ga_chunk_seed(chunk_id)
    error("function stub", 2)
end

---@param chunk_id integer
---@param lbp_hash integer
---@return integer
function ga_lbp_seed_pos(chunk_id, lbp_hash)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@return integer
function ga_block_seed_pos(level, bp)
    error("function stub", 2)
end

---@param var string
---@return boolean
function ga_exists(var)
    error("function stub", 2)
end

---@param var string
function ga_create_b(var)
    error("function stub", 2)
end

---@param var string
function ga_create_i(var)
    error("function stub", 2)
end

---@param var string
function ga_create_f(var)
    error("function stub", 2)
end

---@param var string
function ga_create_v(var)
    error("function stub", 2)
end

---@param var string
function ga_create_s(var)
    error("function stub", 2)
end

---@param var string
---@param value boolean
function ga_init_b(var, value)
    error("function stub", 2)
end

---@param var string
---@param value integer
function ga_init_i(var, value)
    error("function stub", 2)
end

---@param var string
---@param value number
function ga_init_f(var, value)
    error("function stub", 2)
end

---@param var string
---@param value Vector
function ga_init_v(var, value)
    error("function stub", 2)
end

---@param var string
---@param value string
function ga_init_s(var, value)
    error("function stub", 2)
end

---@param var string
---@return boolean
function ga_get_b(var)
    error("function stub", 2)
end

---@param var string
---@return integer
function ga_get_i(var)
    error("function stub", 2)
end

---@param var string
---@return number
function ga_get_f(var)
    error("function stub", 2)
end

---@param var string
---@return Vector
function ga_get_v(var)
    error("function stub", 2)
end

---@param var string
---@return string
function ga_get_s(var)
    error("function stub", 2)
end

---@param var string
---@return boolean
function ga_b_exists_and_true(var)
    error("function stub", 2)
end

---@param var string
---@param value boolean
function ga_set_b(var, value)
    error("function stub", 2)
end

---@param var string
---@param value integer
function ga_set_i(var, value)
    error("function stub", 2)
end

---@param var string
---@param value number
function ga_set_f(var, value)
    error("function stub", 2)
end

---@param var string
---@param value Vector
function ga_set_v(var, value)
    error("function stub", 2)
end

---@param var string
---@param value string
function ga_set_s(var, value)
    error("function stub", 2)
end

---@param var string
function ga_toggle_b(var)
    error("function stub", 2)
end

---@param var string
---@param delta integer
function ga_set_i_by_delta(var, delta)
    error("function stub", 2)
end

---@param var string
---@param delta number
function ga_set_f_by_delta(var, delta)
    error("function stub", 2)
end

---@param var string
---@param delta Vector
function ga_set_v_by_delta(var, delta)
    error("function stub", 2)
end

---@param var string
---@return boolean
function ga_exists_sys_for_get(var)
    error("function stub", 2)
end

---@param var string
---@return boolean
function ga_exists_sys_for_set(var)
    error("function stub", 2)
end

---@param var string
---@return boolean
function ga_get_sys_b(var)
    error("function stub", 2)
end

---@param var string
---@return integer
function ga_get_sys_i(var)
    error("function stub", 2)
end

---@param var string
---@return number
function ga_get_sys_f(var)
    error("function stub", 2)
end

---@param var string
---@return Vector
function ga_get_sys_v(var)
    error("function stub", 2)
end

---@param var string
---@return string
function ga_get_sys_s(var)
    error("function stub", 2)
end

---@param var string
---@param value boolean
function ga_set_sys_b(var, value)
    error("function stub", 2)
end

---@param var string
---@param value integer
function ga_set_sys_i(var, value)
    error("function stub", 2)
end

---@param var string
---@param value number
function ga_set_sys_f(var, value)
    error("function stub", 2)
end

---@param var string
---@param value Vector
function ga_set_sys_v(var, value)
    error("function stub", 2)
end

---@param var string
---@param value string
function ga_set_sys_s(var, value)
    error("function stub", 2)
end

---@param var string
---@return boolean
function ga_package_var_exists(var)
    error("function stub", 2)
end

---@param var string
---@param value boolean
function ga_package_init_b(var, value)
    error("function stub", 2)
end

---@param var string
---@param value integer
function ga_package_init_i(var, value)
    error("function stub", 2)
end

---@param var string
---@param value number
function ga_package_init_f(var, value)
    error("function stub", 2)
end

---@param var string
---@param value Vector
function ga_package_init_v(var, value)
    error("function stub", 2)
end

---@param var string
---@param value string
function ga_package_init_s(var, value)
    error("function stub", 2)
end

---@param var string
---@return boolean
function ga_package_get_b(var)
    error("function stub", 2)
end

---@param var string
---@return integer
function ga_package_get_i(var)
    error("function stub", 2)
end

---@param var string
---@return number
function ga_package_get_f(var)
    error("function stub", 2)
end

---@param var string
---@return Vector
function ga_package_get_v(var)
    error("function stub", 2)
end

---@param var string
---@return string
function ga_package_get_s(var)
    error("function stub", 2)
end

---@param var string
---@param value boolean
function ga_package_set_b(var, value)
    error("function stub", 2)
end

---@param var string
---@param value integer
function ga_package_set_i(var, value)
    error("function stub", 2)
end

---@param var string
---@param value number
function ga_package_set_f(var, value)
    error("function stub", 2)
end

---@param var string
---@param value Vector
function ga_package_set_v(var, value)
    error("function stub", 2)
end

---@param var string
---@param value string
function ga_package_set_s(var, value)
    error("function stub", 2)
end

---@param var string
function package_var_remove(var)
    error("function stub", 2)
end

---@param package string
---@param var string
---@return boolean
function ga_package2_var_exists(package, var)
    error("function stub", 2)
end

---@param package string
---@param var string
---@param value boolean
function ga_package2_init_b(package, var, value)
    error("function stub", 2)
end

---@param package string
---@param var string
---@param value integer
function ga_package2_init_i(package, var, value)
    error("function stub", 2)
end

---@param package string
---@param var string
---@param value number
function ga_package2_init_f(package, var, value)
    error("function stub", 2)
end

---@param package string
---@param var string
---@param value Vector
function ga_package2_init_v(package, var, value)
    error("function stub", 2)
end

---@param package string
---@param var string
---@param value string
function ga_package2_init_s(package, var, value)
    error("function stub", 2)
end

---@param package string
---@param var string
---@return boolean
function ga_package2_get_b(package, var)
    error("function stub", 2)
end

---@param package string
---@param var string
---@return integer
function ga_package2_get_i(package, var)
    error("function stub", 2)
end

---@param package string
---@param var string
---@return number
function ga_package2_get_f(package, var)
    error("function stub", 2)
end

---@param package string
---@param var string
---@return Vector
function ga_package2_get_v(package, var)
    error("function stub", 2)
end

---@param package string
---@param var string
---@return string
function ga_package2_get_s(package, var)
    error("function stub", 2)
end

---@param package string
---@param var string
function ga_package2_var_remove(package, var)
    error("function stub", 2)
end

---@param var string
---@return boolean
function ga_dyn_exists(var)
    error("function stub", 2)
end

---@param var string
function ga_dyn_create_b(var)
    error("function stub", 2)
end

---@param var string
function ga_dyn_create_i(var)
    error("function stub", 2)
end

---@param var string
function ga_dyn_create_f(var)
    error("function stub", 2)
end

---@param var string
function ga_dyn_create_v(var)
    error("function stub", 2)
end

---@param var string
function ga_dyn_create_s(var)
    error("function stub", 2)
end

---@param var string
---@param value boolean
function ga_dyn_init_b(var, value)
    error("function stub", 2)
end

---@param var string
---@param value integer
function ga_dyn_init_i(var, value)
    error("function stub", 2)
end

---@param var string
---@param value number
function ga_dyn_init_f(var, value)
    error("function stub", 2)
end

---@param var string
---@param value Vector
function ga_dyn_init_v(var, value)
    error("function stub", 2)
end

---@param var string
---@param value string
function ga_dyn_init_s(var, value)
    error("function stub", 2)
end

---@param var string
---@return boolean
function ga_dyn_get_b(var)
    error("function stub", 2)
end

---@param var string
---@return integer
function ga_dyn_get_i(var)
    error("function stub", 2)
end

---@param var string
---@return number
function ga_dyn_get_f(var)
    error("function stub", 2)
end

---@param var string
---@return Vector
function ga_dyn_get_v(var)
    error("function stub", 2)
end

---@param var string
---@return string
function ga_dyn_get_s(var)
    error("function stub", 2)
end

---@param var string
---@return boolean
function ga_dyn_b_exists_and_true(var)
    error("function stub", 2)
end

---@param var string
---@param value boolean
function ga_dyn_set_b(var, value)
    error("function stub", 2)
end

---@param var string
---@param value integer
function ga_dyn_set_i(var, value)
    error("function stub", 2)
end

---@param var string
---@param value number
function ga_dyn_set_f(var, value)
    error("function stub", 2)
end

---@param var string
---@param value Vector
function ga_dyn_set_v(var, value)
    error("function stub", 2)
end

---@param var string
---@param value string
function ga_dyn_set_s(var, value)
    error("function stub", 2)
end

---@param var string
function ga_dyn_toggle_b(var)
    error("function stub", 2)
end

---@param var string
---@param delta integer
function ga_dyn_set_i_by_delta(var, delta)
    error("function stub", 2)
end

---@param var string
---@param delta number
function ga_dyn_set_f_by_delta(var, delta)
    error("function stub", 2)
end

---@param var string
---@param delta Vector
function ga_dyn_set_v_by_delta(var, delta)
    error("function stub", 2)
end

---@param var string
function ga_dyn_remove(var)
    error("function stub", 2)
end

---@param prefix string
function ga_dyn_node_itr_start(prefix)
    error("function stub", 2)
end

---@return string
function ga_dyn_node_itr_next()
    error("function stub", 2)
end

---@param prefix string
function ga_dyn_leaf_itr_start(prefix)
    error("function stub", 2)
end

---@return string
function ga_dyn_leaf_itr_next()
    error("function stub", 2)
end

function ga_dyn_dump()
    error("function stub", 2)
end

---@param tex_name string
function ga_tex_keep_alive(tex_name)
    error("function stub", 2)
end

---@param sound string
---@return string
function ga_sound_name_to_fn(sound)
    error("function stub", 2)
end

---@param prefix string
---@return table
function ga_get_sound_names_with_prefix(prefix)
    error("function stub", 2)
end

---@param sound string
function ga_play_sound(sound)
    error("function stub", 2)
end

---@param sound string
function ga_play_sound_menu(sound)
    error("function stub", 2)
end

---@param sound string
function ga_play_music(sound)
    error("function stub", 2)
end

function ga_stop_music()
    error("function stub", 2)
end

---@return string
function ga_get_current_music_fn()
    error("function stub", 2)
end

---@param playlist string
function ga_play_playlist(playlist)
    error("function stub", 2)
end

---@param playlist string
---@return boolean
function ga_playlist_exists(playlist)
    error("function stub", 2)
end

---@param value boolean
function ga_enable_non_escape_binds(value)
    error("function stub", 2)
end

---@param action string
---@return string
function ga_what_binds_to_action(action)
    error("function stub", 2)
end

---@param name string
---@return number
function ga_mesh_get_radius(name)
    error("function stub", 2)
end

---@param name string
---@return number
function ga_mesh_get_inv_radius(name)
    error("function stub", 2)
end

---@return string
function ga_get_package_name()
    error("function stub", 2)
end

---@return boolean
function ga_is_cheating_enabled()
    error("function stub", 2)
end

---@return boolean
function ga_get_hardcore_mode()
    error("function stub", 2)
end

---@param value boolean
function ga_set_hardcore_mode(value)
    error("function stub", 2)
end

---@return boolean
function ga_genesis()
    error("function stub", 2)
end

---@return boolean
function ga_kill_player()
    error("function stub", 2)
end

---@return boolean
function ga_use_object_exists()
    error("function stub", 2)
end

---@return string
function ga_use_object_get_type()
    error("function stub", 2)
end

---@return boolean
function ga_look_object_bent_exists()
    error("function stub", 2)
end

---@return integer
function ga_look_object_bent_get_chunk_id()
    error("function stub", 2)
end

---@return LocalBlockPos
function ga_look_object_bent_get_lbp()
    error("function stub", 2)
end

---@return boolean
function ga_look_object_ment_exists()
    error("function stub", 2)
end

---@return integer
function ga_look_object_ment_inst_id()
    error("function stub", 2)
end

---@return boolean
function ga_look_object_block_exists()
    error("function stub", 2)
end

---@return integer
function ga_look_object_block_get_chunk_id()
    error("function stub", 2)
end

---@return LocalBlockPos
function ga_look_object_block_get_lbp()
    error("function stub", 2)
end

---@return integer
function ga_look_object_block_get_normal_side()
    error("function stub", 2)
end

---@param msg string
---@param duration number
function ga_hud_msg(msg, duration)
    error("function stub", 2)
end

---@param damage integer
---@param dir Vector
function ga_hud_reg_damage_from_dir(damage, dir)
    error("function stub", 2)
end

---@param damage integer
---@param dir Vector
---@param color Vector
function ga_hud_reg_damage_from_dir_color(damage, dir, color)
    error("function stub", 2)
end

---@param name string
---@param tex string
---@param dir Vector
---@param duration number
function ga_hud_reg_dir_tex(name, tex, dir, duration)
    error("function stub", 2)
end

function ga_shrink()
    error("function stub", 2)
end

---@param lp Vector
function ga_shrink2(lp)
    error("function stub", 2)
end

function ga_grow()
    error("function stub", 2)
end

---@param lp Vector
function ga_grow2(lp)
    error("function stub", 2)
end

---@param path string
---@param offset Vector
function ga_tele(path, offset)
    error("function stub", 2)
end

function ga_tele_pink()
    error("function stub", 2)
end

---@param lp Vector
---@return boolean
function ga_tele_pink2(lp)
    error("function stub", 2)
end

function ga_tele_blue()
    error("function stub", 2)
end

---@param lp Vector
function ga_tele_blue2(lp)
    error("function stub", 2)
end

---@param lp Vector
function ga_tele_same_level(lp)
    error("function stub", 2)
end

---@param level_delta integer
---@return integer
function ga_get_fertile_radius(level_delta)
    error("function stub", 2)
end

---@param level_delta integer
---@param radius integer
function ga_set_fertile_radius(level_delta, radius)
    error("function stub", 2)
end

---@param level_delta integer
---@return integer
function ga_get_level_radius(level_delta)
    error("function stub", 2)
end

---@param level_delta integer
---@param radius integer
function ga_set_level_radius(level_delta, radius)
    error("function stub", 2)
end

---@param win_name string
function ga_window_push(win_name)
    error("function stub", 2)
end

function ga_window_pop()
    error("function stub", 2)
end

function ga_window_pop_all()
    error("function stub", 2)
end

---@param win_name string
function ga_main_menu_push(win_name)
    error("function stub", 2)
end

function ga_main_menu_pop()
    error("function stub", 2)
end

---@param return_to_game boolean
function ga_main_menu_pop_all(return_to_game)
    error("function stub", 2)
end

---@param win_name string
---@param priority integer
function ga_hud_window_add(win_name, priority)
    error("function stub", 2)
end

---@param win_name string
function ga_hud_window_remove(win_name)
    error("function stub", 2)
end

---@return integer
function ga_get_viewer_chunk_id()
    error("function stub", 2)
end

---@param level integer
---@return integer
function ga_get_viewer_ancestor_chunk_id(level)
    error("function stub", 2)
end

---@return string
function ga_get_viewer_chunk_bt()
    error("function stub", 2)
end

---@return integer
function ga_get_viewer_level()
    error("function stub", 2)
end

---@return Vector
function ga_get_viewer_offset()
    error("function stub", 2)
end

---@param level integer
---@return Vector
function ga_get_viewer_lp(level)
    error("function stub", 2)
end

---@param level integer
---@return BlockPos
function ga_get_viewer_bp(level)
    error("function stub", 2)
end

---@return string
function ga_get_viewer_path()
    error("function stub", 2)
end

---@return string
function ga_get_viewer_path_ext()
    error("function stub", 2)
end

---@param level integer
---@param lp Vector
---@return Vector
function ga_get_vec_to_viewer(level, lp)
    error("function stub", 2)
end

---@param chunk_id integer
---@param lbp_hash integer
---@return number
function ga_lbp_dist_to_viewer(chunk_id, lbp_hash)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@return number
function ga_block_dist_to_viewer(level, bp)
    error("function stub", 2)
end

---@param inst_id integer
---@return Vector
function ga_ment_get_var_special_vec_to_viewer(inst_id)
    error("function stub", 2)
end

---@param inst_id integer
---@return number
function ga_ment_get_var_special_dist_to_viewer(inst_id)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@return string
function ga_bent_get_type(level, bp)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param type string
---@param rl number
function ga_bent_add(level, bp, type, rl)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param type string
---@param param integer
---@param rl number
function ga_bent_add_i(level, bp, type, param, rl)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param type string
---@param param string
---@param rl number
function ga_bent_add_s(level, bp, type, param, rl)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param value integer
---@param rl number
function ga_bent_set_param_i(level, bp, value, rl)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param value string
---@param rl number
function ga_bent_set_param_s(level, bp, value, rl)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@return integer
function ga_bent_get_param_i(level, bp)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@return string
function ga_bent_get_param_s(level, bp)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param num_sec integer
function ga_bent_remove_temp(level, bp, num_sec)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
function ga_bent_remove_perm(level, bp)
    error("function stub", 2)
end

---@param level integer
---@param lp Vector
---@param radius number
---@return table
function ga_bent_sphere_query(level, lp, radius)
    error("function stub", 2)
end

---@param chunk_id integer
---@param bent_type string
---@return table
function ga_search_for_bent_in_chunk(chunk_id, bent_type)
    error("function stub", 2)
end

---@param type string
---@param var string
---@return boolean
function ga_ment_type_var_exists(type, var)
    error("function stub", 2)
end

---@param type string
---@param var string
---@return boolean
function ga_ment_get_static_b(type, var)
    error("function stub", 2)
end

---@param type string
---@param var string
---@return integer
function ga_ment_get_static_i(type, var)
    error("function stub", 2)
end

---@param type string
---@param var string
---@return number
function ga_ment_get_static_f(type, var)
    error("function stub", 2)
end

---@param type string
---@param var string
---@return Vector
function ga_ment_get_static_v(type, var)
    error("function stub", 2)
end

---@param type string
---@param var string
---@return string
function ga_ment_get_static_s(type, var)
    error("function stub", 2)
end

---@param type string
---@param var string
---@return boolean
function ga_ment_static_b_exists_and_true(type, var)
    error("function stub", 2)
end

---@param level integer
---@param lp Vector
---@param type string
function ga_ment_start(level, lp, type)
    error("function stub", 2)
end

function ga_ment_end()
    error("function stub", 2)
end

---@param key string
---@param value boolean
function ga_ment_init_set_b(key, value)
    error("function stub", 2)
end

---@param key string
---@param value integer
function ga_ment_init_set_i(key, value)
    error("function stub", 2)
end

---@param key string
---@param value number
function ga_ment_init_set_f(key, value)
    error("function stub", 2)
end

---@param key string
---@param value Vector
function ga_ment_init_set_v(key, value)
    error("function stub", 2)
end

---@param key string
---@param value string
function ga_ment_init_set_s(key, value)
    error("function stub", 2)
end

---@param inst_id integer
---@param var string
---@return boolean
function ga_ment_var_exists(inst_id, var)
    error("function stub", 2)
end

---@param inst_id integer
---@param var string
---@return boolean
function ga_ment_b_exists_and_true(inst_id, var)
    error("function stub", 2)
end

---@param inst_id integer
---@param var string
---@return boolean
function ga_ment_get_b(inst_id, var)
    error("function stub", 2)
end

---@param inst_id integer
---@param var string
---@return integer
function ga_ment_get_i(inst_id, var)
    error("function stub", 2)
end

---@param inst_id integer
---@param var string
---@return number
function ga_ment_get_f(inst_id, var)
    error("function stub", 2)
end

---@param inst_id integer
---@param var string
---@return Vector
function ga_ment_get_v(inst_id, var)
    error("function stub", 2)
end

---@param inst_id integer
---@param var string
---@return string
function ga_ment_get_s(inst_id, var)
    error("function stub", 2)
end

---@param inst_id integer
---@param var string
---@param rl number
function ga_ment_set_var_rt_only(inst_id, var, rl)
    error("function stub", 2)
end

---@param inst_id integer
---@param var string
---@param value boolean
function ga_ment_set_b(inst_id, var, value)
    error("function stub", 2)
end

---@param inst_id integer
---@param var string
---@param value integer
function ga_ment_set_i(inst_id, var, value)
    error("function stub", 2)
end

---@param inst_id integer
---@param var string
---@param value number
function ga_ment_set_f(inst_id, var, value)
    error("function stub", 2)
end

---@param inst_id integer
---@param var string
---@param value Vector
function ga_ment_set_v(inst_id, var, value)
    error("function stub", 2)
end

---@param inst_id integer
---@param var string
---@param value string
function ga_ment_set_s(inst_id, var, value)
    error("function stub", 2)
end

---@param inst_id integer
---@param var string
function ga_ment_toggle_b(inst_id, var)
    error("function stub", 2)
end

---@param inst_id integer
---@param var string
---@param delta integer
function ga_ment_set_i_by_delta(inst_id, var, delta)
    error("function stub", 2)
end

---@param inst_id integer
---@param var string
---@param delta number
function ga_ment_set_f_by_delta(inst_id, var, delta)
    error("function stub", 2)
end

---@param inst_id integer
---@param var string
---@param delta Vector
function ga_ment_set_v_by_delta(inst_id, var, delta)
    error("function stub", 2)
end

---@param inst_id integer
---@return integer
function ga_ment_inst_id_to_code_id(inst_id)
    error("function stub", 2)
end

---@param code_id integer
---@return integer
function ga_ment_code_id_to_inst_id(code_id)
    error("function stub", 2)
end

---@param inst_id integer
---@return boolean
function ga_ment_exists(inst_id)
    error("function stub", 2)
end

---@param inst_id integer
function ga_ment_remove(inst_id)
    error("function stub", 2)
end

---@param inst_id integer
---@return string
function ga_ment_get_type(inst_id)
    error("function stub", 2)
end

---@param inst_id integer
---@return Vector
function ga_ment_get_lp(inst_id)
    error("function stub", 2)
end

---@param inst_id integer
---@return Vector
function ga_ment_get_sllp(inst_id)
    error("function stub", 2)
end

---@param inst_id integer
---@return integer
function ga_ment_get_level(inst_id)
    error("function stub", 2)
end

---@param inst_id integer
---@return integer
function ga_ment_get_chunk_id(inst_id)
    error("function stub", 2)
end

---@param inst_id integer
---@return number
function ga_ment_get_radius(inst_id)
    error("function stub", 2)
end

---@param inst_id integer
function ga_ment_dump(inst_id)
    error("function stub", 2)
end

---@param level integer
---@param min_level integer
---@param max_level integer
---@param lp Vector
---@param radius number
---@return table
function ga_ment_sphere_query(level, min_level, max_level, lp, radius)
    error("function stub", 2)
end

---@param inst_id integer
---@param alarm_game_time number
---@param alarm_name string
function ga_ment_set_alarm(inst_id, alarm_game_time, alarm_name)
    error("function stub", 2)
end

---@param inst_id integer
---@param level integer
---@param alarm_level_time number
---@param alarm_name string
function ga_ment_set_alarm_on_level(inst_id, level, alarm_level_time, alarm_name)
    error("function stub", 2)
end

function ga_ment_all_dump()
    error("function stub", 2)
end

---@param args table
function ga_particle_add(args)
    error("function stub", 2)
end

---@param args table
function ga_particle_explosion(args)
    error("function stub", 2)
end

---@param args table
function ga_particle_trail(args)
    error("function stub", 2)
end

---@param args table
function ga_particle_ring(args)
    error("function stub", 2)
end

---@param bt string
---@return boolean
function ga_bt_exists(bt)
    error("function stub", 2)
end

---@param bt string
---@param var string
---@return boolean
function ga_bt_var_exists(bt, var)
    error("function stub", 2)
end

---@param bt string
---@return boolean
function ga_bt_get_physically_solid(bt)
    error("function stub", 2)
end

---@param prefix string
---@return table
function ga_get_block_names_with_prefix(prefix)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@return string
function ga_block_get(level, bp)
    error("function stub", 2)
end

---@param level integer
---@param vcp BlockPos
---@return string
function ga_get_cocoon_block_of_chunk(level, vcp)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param new_bt string
---@param rl number
function ga_block_change_rl(level, bp, new_bt, rl)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param new_bt string
function ga_block_change_rl_default(level, bp, new_bt)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param new_bt string
function ga_block_change_perm(level, bp, new_bt)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param var string
---@return boolean
function ga_block_var_exists(level, bp, var)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param var string
---@return boolean
function ga_block_get_b(level, bp, var)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param var string
---@return integer
function ga_block_get_i(level, bp, var)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param var string
---@return number
function ga_block_get_f(level, bp, var)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param var string
---@return Vector
function ga_block_get_v(level, bp, var)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param var string
---@return string
function ga_block_get_s(level, bp, var)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param var string
---@return boolean
function ga_block_b_exists_and_true(level, bp, var)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param var string
---@param value boolean
function ga_block_set_b(level, bp, var, value)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param var string
---@param value integer
function ga_block_set_i(level, bp, var, value)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param var string
---@param value number
function ga_block_set_f(level, bp, var, value)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param var string
---@param value Vector
function ga_block_set_v(level, bp, var, value)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param var string
---@param value string
function ga_block_set_s(level, bp, var, value)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param var string
function ga_block_toggle_b(level, bp, var)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param var string
---@param delta integer
function ga_block_set_i_by_delta(level, bp, var, delta)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param var string
---@param delta number
function ga_block_set_f_by_delta(level, bp, var, delta)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@param var string
---@param delta Vector
function ga_block_set_v_by_delta(level, bp, var, delta)
    error("function stub", 2)
end

---@param chunk_id integer
---@return string
function ga_get_most_common_bt_in_chunk(chunk_id)
    error("function stub", 2)
end

---@param chunk_id integer
---@param bt string
---@return table
function ga_search_for_bt_in_chunk(chunk_id, bt)
    error("function stub", 2)
end

---@param chunk_id integer
---@param bt string
---@return table
function ga_search_for_bt_in_chunk_random(chunk_id, bt)
    error("function stub", 2)
end

---@return string
function ga_get_respawn_path()
    error("function stub", 2)
end

---@param path string
---@param lbp BlockPos
function ga_set_respawn_point(path, lbp)
    error("function stub", 2)
end

---@param path string
---@param name_override string
function ga_add_waypoint_sloppy(path, name_override)
    error("function stub", 2)
end

---@param path string
---@param name_override string
function ga_add_waypoint_sloppy_in_only(path, name_override)
    error("function stub", 2)
end

---@param chunk_id integer
---@return integer
function ga_chunk_id_to_level(chunk_id)
    error("function stub", 2)
end

---@param chunk_id integer
---@return BlockPos
function ga_chunk_id_to_vcp(chunk_id)
    error("function stub", 2)
end

---@param chunk_id integer
---@return string
function ga_chunk_id_to_path(chunk_id)
    error("function stub", 2)
end

---@param level integer
---@param vcp BlockPos
---@return integer
function ga_vcp_to_chunk_id(level, vcp)
    error("function stub", 2)
end

---@param path string
---@return integer
function ga_path_to_chunk_id(path)
    error("function stub", 2)
end

---@param chunk_id integer
---@param lbp BlockPos
---@return BlockPos
function ga_chunk_id_and_lbp_to_bp(chunk_id, lbp)
    error("function stub", 2)
end

---@param vcp BlockPos
---@param lbp BlockPos
---@return BlockPos
function ga_lbp_to_bp(vcp, lbp)
    error("function stub", 2)
end

---@param level integer
---@param vcp BlockPos
---@return BlockPos
function ga_vcp_to_bp(level, vcp)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@return BlockPos
function ga_bp_to_vcp(level, bp)
    error("function stub", 2)
end

---@param chunk_id integer
---@return integer
function ga_chunk_id_to_parent_chunk_id(chunk_id)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@return BlockPos
function ga_bp_to_parent_bp(level, bp)
    error("function stub", 2)
end

---@param bp BlockPos
---@return BlockPos
function ga_bp_to_parent_vcp(bp)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@return integer
function ga_bp_to_parent_chunk_id(level, bp)
    error("function stub", 2)
end

---@param level integer
---@param bp BlockPos
---@return string
function ga_bp_to_path(level, bp)
    error("function stub", 2)
end

---@param bp BlockPos
---@return BlockPos
function ga_bp_to_lbp(bp)
    error("function stub", 2)
end

---@param chunk_id integer
---@param offset Vector
---@return Vector
function ga_chunk_id_and_offset_to_lp(chunk_id, offset)
    error("function stub", 2)
end

---@param vcp BlockPos
---@param offset Vector
---@return Vector
function ga_offset_to_lp(vcp, offset)
    error("function stub", 2)
end

---@param source_level integer
---@param target_level integer
---@return table
function ga_level_scale_factor(source_level, target_level)
    error("function stub", 2)
end

---@param source_level integer
---@param target_level integer
---@param source_lp Vector
---@return table
function ga_convert_lp(source_level, target_level, source_lp)
    error("function stub", 2)
end

---@param level integer
---@param lp Vector
---@return table
function ga_finest_chunk_containing_point(level, lp)
    error("function stub", 2)
end

---@param path1 string
---@param path2 string
---@return table
function ga_path_diff(path1, path2)
    error("function stub", 2)
end

---@param look Vector
---@param up Vector
function ga_camera_set_look(look, up)
    error("function stub", 2)
end

---@param travel Vector
function ga_move_set_desired_travel(travel)
    error("function stub", 2)
end

---@param spin number
function ga_move_set_spin(spin)
    error("function stub", 2)
end

---@return boolean
function ga_move_get_on_sure_footing()
    error("function stub", 2)
end

---@param on boolean
function ga_move_set_ledge_guards(on)
    error("function stub", 2)
end

function ga_move_set_body_spirit()
    error("function stub", 2)
end

---@param trans Vector
---@param radius number
---@param bot_to_eye number
---@param eye_to_top number
---@return boolean
function ga_move_set_body_ground(trans, radius, bot_to_eye, eye_to_top)
    error("function stub", 2)
end

---@param trans Vector
---@param radius number
---@param use_true_up boolean
---@return boolean
function ga_move_set_body_fly(trans, radius, use_true_up)
    error("function stub", 2)
end

function ga_player_model_set_look()
    error("function stub", 2)
end

---@param cmd string
function ga_player_model_q2md2_set_cmd(cmd)
    error("function stub", 2)
end

---@param state string
function ga_player_model_q2md2_set_state(state)
    error("function stub", 2)
end

---@param level integer
---@param lp_start Vector
---@param lp_end Vector
---@return boolean
function ga_vis_test_level(level, lp_start, lp_end)
    error("function stub", 2)
end

---@param look Vector
---@param up Vector
function ga_camera_set_look(look, up)
    error("function stub", 2)
end

---@param travel Vector
function ga_move_set_desired_travel(travel)
    error("function stub", 2)
end

---@param spin number
function ga_move_set_spin(spin)
    error("function stub", 2)
end

---@return boolean
function ga_move_get_on_sure_footing()
    error("function stub", 2)
end

---@param on boolean
function ga_move_set_ledge_guards(on)
    error("function stub", 2)
end

function ga_move_set_body_spirit()
    error("function stub", 2)
end

---@param trans Vector
---@param radius number
---@param bot_to_eye number
---@param eye_to_top number
---@return boolean
function ga_move_set_body_ground(trans, radius, bot_to_eye, eye_to_top)
    error("function stub", 2)
end

---@param trans Vector
---@param radius number
---@param use_true_up boolean
---@return boolean
function ga_move_set_body_fly(trans, radius, use_true_up)
    error("function stub", 2)
end

function ga_player_model_set_look()
    error("function stub", 2)
end

---@param cmd string
function ga_player_model_q2md2_set_cmd(cmd)
    error("function stub", 2)
end

---@param state string
function ga_player_model_q2md2_set_state(state)
    error("function stub", 2)
end

---@param level integer
---@param lp_start Vector
---@param lp_end Vector
---@return boolean
function ga_vis_test_level(level, lp_start, lp_end)
    error("function stub", 2)
end

function ga_render_push_matrix()
    error("function stub", 2)
end

function ga_render_pop_matrix()
    error("function stub", 2)
end

function ga_render_matrix_load_identity()
    error("function stub", 2)
end

---@param m11 number
---@param m12 number
---@param m13 number
---@param m14 number
---@param m21 number
---@param m22 number
---@param m23 number
---@param m24 number
---@param m31 number
---@param m32 number
---@param m33 number
---@param m34 number
---@param m41 number
---@param m42 number
---@param m43 number
---@param m44 number
function ga_render_matrix_row_major(m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44)
    error("function stub", 2)
end

---@param trans_x number
---@param trans_y number
---@param trans_z number
function ga_render_matrix_translated(trans_x, trans_y, trans_z)
    error("function stub", 2)
end

---@param scale_x number
---@param scale_y number
---@param scale_z number
function ga_render_matrix_scaled(scale_x, scale_y, scale_z)
    error("function stub", 2)
end

---@param angle number
---@param axis Vector
function ga_render_matrix_rotated(angle, axis)
    error("function stub", 2)
end

---@param look Vector
---@param up Vector
---@param left Vector
function ga_render_matrix_frame(look, up, left)
    error("function stub", 2)
end

---@param inst_id integer
function ga_render_matrix_frame_from_ment(inst_id)
    error("function stub", 2)
end

---@param inst_id integer
function ga_render_ment_typical(inst_id)
    error("function stub", 2)
end

---@param mesh_name string
function ga_render_mesh(mesh_name)
    error("function stub", 2)
end

---@param mesh_name string
---@param tex_name string
function ga_render_mesh_with_tex(mesh_name, tex_name)
    error("function stub", 2)
end

---@param v1 Vector
---@param v2 Vector
function ga_render_line(v1, v2)
    error("function stub", 2)
end

---@param v1 Vector
---@param v2 Vector
---@param thickness number
function ga_render_line_thick(v1, v2, thickness)
    error("function stub", 2)
end

---@param color Vector
function ga_render_color(color)
    error("function stub", 2)
end

function ga_render_clear_depth_buffer()
    error("function stub", 2)
end

---@return string
function ga_reboot_dyn_itr_get()
    error("function stub", 2)
end

function ga_reboot_dyn_itr_next()
    error("function stub", 2)
end

---@return boolean
function ga_reboot_dyn_itr_at_end()
    error("function stub", 2)
end

function ga_reboot_dyn_itr_save()
    error("function stub", 2)
end

---@param file_name string
---@return integer
function ga_open_file_for_writing(file_name)
    error("function stub", 2)
end

---@param handle integer
---@param str string
function ga_write(handle, str)
    error("function stub", 2)
end

---@param handle integer
function ga_close_file(handle)
    error("function stub", 2)
end

---@return boolean
function ga_get_is_colorblind()
    error("function stub", 2)
end

---@param color Vector
---@return Vector
function ga_get_colorblind_closest(color)
    error("function stub", 2)
end

---@param num integer
---@return Vector
function ga_get_colorblind_bynum(num)
    error("function stub", 2)
end

---@param num integer
---@param color Vector
function ga_set_colorblind_bynum(num, color)
    error("function stub", 2)
end

---@param code string
---@return Vector
function ga_color_code_to_vec(code)
    error("function stub", 2)
end

---@param color Vector
---@return string
function ga_color_vec_to_code(color)
    error("function stub", 2)
end

---@param input string
---@return string
function ga_txt_strip_esc_seq(input)
    error("function stub", 2)
end

---@param str string
function ga_copy_to_clipboard(str)
    error("function stub", 2)
end

---@return string
function ga_paste_from_clipboard()
    error("function stub", 2)
end

