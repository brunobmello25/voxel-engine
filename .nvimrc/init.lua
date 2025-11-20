vim.keymap.set("n", "<M-m>", function()
	vim.cmd("!bin/build.sh")
end, {})

local dap = require("dap")

dap.configurations.cpp = {
	{
		name = "Debug Game (codelldb)",
		type = "codelldb",
		request = "launch",
		program = vim.fn.getcwd() .. "/target/linux_app",
		cwd = vim.fn.getcwd(),
		stopOnEntry = false,
	},
}
