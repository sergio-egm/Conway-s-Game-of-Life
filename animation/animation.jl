using Plots

function load_frame(path::String , size::Int)
    data = read(path)
    grid = reshape(data , size , size)
    return grid
end

size = open("INPUT.dat") do io
    parse(Int , readline(io))
end

grid = load_frame("data/frame.bin" , size)

savefig(heatmap(grid' , colorbar = false , axis = false) , "frame.png")