using Plots

function load_frame(path::String , size::Int)
    data = read(path)
    grid = reshape(data , size , size)
    return grid
end

grid = load_frame("data/frame.bin" , 5)

savefig(heatmap(grid' , colorbar = false , axis = false) , "frame.png")